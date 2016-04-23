<?php

namespace __SystemLib {
  class ArchiveEntryStat {
    public function __construct(
      public ?int $crc,
      public int $size,
      public ?int $compresedSize,
      public int $timestamp,
    ) {
    }
  }

  abstract class ArchiveHandler {
    protected Map<string, ArchiveEntryData> $entries = Map { };
    protected ?string $alias;
    protected ?string $stub;
    protected array<string, array<int, int>> $fileOffsets = [];
    protected string $apiVersion = '1.0.0';
    protected $metadata;
    protected ?string $signature;
    protected $compressed = false;

    abstract public function getStream(string $path): resource;
    abstract public function extractAllTo(string $path);
    abstract public function addFile(string $path, string $archivePath): bool;
    abstract public function close(): void;

    abstract public function __construct(
      string $path,
      bool $preventHaltTokenCheck = true
    );

    public function stat(string $path): ?ArchiveEntryStat {
      return $this->getEntriesMap()->get($path);
    }

    public function getAlias(): ?string {
      return $this->alias;
    }

    public function setAlias(string $alias) {
      //TODO
    }

    public function getStub(): ?string {
      return $this->stub;
    }

    public function setStub(string $stub, int $len = -1) {
      //TODO
    }

    public function count(): int {
      return $this->entries->count();
    }

    public function apiVersion(): string {
      return $this->apiVersion;
    }

    public function getMetadata() {
      return $this->metadata;
    }

    public function hasMetadata() {
      return $this->metadata !== null;
    }

    public function getSignature(): string {
      return $this->signature;
    }

    public function isCompressed() {
      return $this->compressed();
    }

    // Custom methods used by Phar class internally

    public function getEntriesMap(): Map<string, ArchiveEntryStat> {
      return $this->entries;
    }
  }
}
