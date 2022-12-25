CREATE TABLE public."SampleEntityWithAllTypes" (
    "Id" VARCHAR(255) NOT NULL,
    "SampleBoolean" BOOLEAN,
    "SampleSmallInt" SMALLINT,
    "SampleInteger" INTEGER,
    "SampleLong" BIGINT,
    "SampleFloat" FLOAT4,
    "SampleDouble" FLOAT8,
    CONSTRAINT "TestEntityPK" PRIMARY KEY ("Id"));